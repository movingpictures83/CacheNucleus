#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "CacheNucleusPlugin.h"



void CacheNucleusPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void CacheNucleusPlugin::run() {}

void CacheNucleusPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "cache-sim ";
myCommand += myParameters["algorithm"]+" ";
myCommand += myParameters["size"]+" ";
myCommand += myParameters["name"]+" -f ";
myCommand += PluginManager::addPrefix(myParameters["workload"]);
myCommand += " > ";
myCommand += outputfile;
 system(myCommand.c_str());
}

PluginProxy<CacheNucleusPlugin> CacheNucleusPluginProxy = PluginProxy<CacheNucleusPlugin>("CacheNucleus", PluginManager::getInstance());
