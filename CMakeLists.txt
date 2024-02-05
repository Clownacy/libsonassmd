cmake_minimum_required(VERSION 3.0...3.28.1)

project(sonassmd LANGUAGES CXX)

add_library(sonassmd STATIC
	"assembleable.cpp"
	"assembleable.h"
	"assembler.cpp"
	"assembler.h"
	"common.cpp"
	"common.h"
	"dynamic-pattern-load-cues.cpp"
	"dynamic-pattern-load-cues.h"
	"object.cpp"
	"object.h"
	"object-layout.cpp"
	"object-layout.h"
	"sprite-frame.cpp"
	"sprite-frame.h"
	"sprite-mappings.cpp"
	"sprite-mappings.h"
	"sprite-piece.cpp"
	"sprite-piece.h"
	"tile.cpp"
	"tile.h"
	"tiles.cpp"
	"tiles.h"
	"clowncommon/clowncommon.h"
)

add_subdirectory("clownassembler" EXCLUDE_FROM_ALL)
target_link_libraries(sonassmd PRIVATE clownassembler_core)
