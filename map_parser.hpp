#ifndef MAP_PARSER_HPP
#define MAP_PARSER_HPP

#include <cstring>
#include <mlk/filesystem/filesystem.h>

struct MapDatafileHeader
{
	char sig[4];
	int ver;
	int size;
	int swaplen;
	int num_itemtypes;
	int num_items;
	int num_rawdata;
	int item_area_size;
	int data_area_size;
	
	bool valid() const noexcept {
		return ((std::memcmp(sig, "DATA", 4) == 0) && (ver == 4));
	}
	
	int sizeToVersion() const noexcept {
		return	sizeof(MapDatafileHeader) +
				(num_itemtypes * 12) +
				(num_items * sizeof(int)) +
				((num_rawdata * sizeof(int)) * 2);
	}
};

class MapParser {
	mlk::fs::file_handle mFileHandle;
	mlk::data_packet mWriteData;
	
public:
	bool open(const std::string& path) {
		if(!mFileHandle.reopen(path, std::ios::in | std::ios::binary))
			return false;
		
		auto data(mFileHandle.read_all());
		auto* ptr(reinterpret_cast<MapDatafileHeader*>(data.data()));
		if(!ptr->valid()) return false;
		
		// fix data
		// +8 -> jump to item data (after type_and_id and length)
		data[ptr->sizeToVersion() + 8] = 0x01;
		data[ptr->sizeToVersion() + 8 + 1] = 0x00;
		mWriteData = data;
		
		return true;
	}
	
	bool save() {
		if(!mFileHandle.reopen(mFileHandle.path(), std::ios::out | std::ios::binary))
			return false;
		mFileHandle.write(mWriteData);
		return true;
	}
};

#endif // MAP_PARSER_HPP
