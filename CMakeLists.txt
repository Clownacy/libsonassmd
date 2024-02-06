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

##################
# clownassembler #
##################

add_subdirectory("clownassembler" EXCLUDE_FROM_ALL)
target_link_libraries(sonassmd PRIVATE clownassembler_core)

##########
# mdcomp #
##########

# We're using the Shell Extension's fork of FW-KENSC/mdcomp because
# upstream has a hard dependency on Boost which is revolting.
set(mdcomp_directory "FW-KENSC-ShellExt/FW-KENSC-ShellExt/FW-KENSC")

add_library(mdcomp STATIC
	# General stuff.
	"${mdcomp_directory}/basic_decoder.h"
	"${mdcomp_directory}/bigendian_io.h"
	"${mdcomp_directory}/bitstream.h"
	"${mdcomp_directory}/ignore_unused_variable_warning.h"
	"${mdcomp_directory}/lzss.h"
	"${mdcomp_directory}/moduled_adaptor.h"
	# Format-specific stuff.
	"${mdcomp_directory}/comper.cc"
	"${mdcomp_directory}/comper.h"
	"${mdcomp_directory}/kosinski.cc"
	"${mdcomp_directory}/kosinski.h"
	"${mdcomp_directory}/kosplus.cc"
	"${mdcomp_directory}/kosplus.h"
	"${mdcomp_directory}/nemesis.cc"
	"${mdcomp_directory}/nemesis.h"
)

target_include_directories(mdcomp PUBLIC ${mdcomp_directory})

target_link_libraries(sonassmd PRIVATE mdcomp)
