/** @file version.h */

#ifndef GEM_HWMONITOR_VERSION_H
#define GEM_HWMONITOR_VERSION_H

#ifndef DOXYGEN_IGNORE_THIS

#include "config/PackageInfo.h"

namespace gem {
  namespace hwMonitor {

#define GEMHWMONITOR_VERSION_MAJOR 1
#define GEMHWMONITOR_VERSION_MINOR 0
#define GEMHWMONITOR_VERSION_PATCH 0
#define GEMHWMONITOR_PREVIOUS_VERSIONS "0.0.0,0.1.0,0.2.0,0.2.1,0.3.0,0.99.0,0.99.1"

#define GEMHWMONITOR_VERSION_CODE PACKAGE_VERSION_CODE(GEMHWMONITOR_VERSION_MAJOR, GEMHWMONITOR_VERSION_MINOR, GEMHWMONITOR_VERSION_PATCH)

#ifndef GEMHWMONITOR_PREVIOUS_VERSIONS
#define GEMHWMONITOR_FULL_VERSION_LIST PACKAGE_VERSION_STRING(GEMHWMONITOR_VERSION_MAJOR, GEMHWMONITOR_VERSION_MINOR, GEMHWMONITOR_VERSION_PATCH)
#else
#define GEMHWMONITOR_FULL_VERSION_LIST GEMHWMONITOR_PREVIOUS_VERSIONS "," PACKAGE_VERSION_STRING(GEMHWMONITOR_VERSION_MAJOR, GEMHWMONITOR_VERSION_MINOR, GEMHWMONITOR_VERSION_PATCH)
#endif

    const std::string project     = "cmsgemos";
    const std::string package     = "hwMonitor";
    const std::string versions    = GEMHWMONITOR_FULL_VERSION_LIST;
    const std::string summary     = "GEM hwMonitor";
    const std::string description = "";
    const std::string authors     = "GEM Online Systems Group";
    const std::string link        = "https://cms-gem-daq-project.github.io/cmsgemos/";

    config::PackageInfo getPackageInfo();
    void checkPackageDependencies();
    std::set<std::string, std::less<std::string> > getPackageDependencies();
  }
}

#endif // DOXYGEN_IGNORE_THIS

#endif // GEM_HWMONITOR_VERSION_H
