#ifndef GEM_ONLINEDB_AMC13CONFIGURATION_H
#define GEM_ONLINEDB_AMC13CONFIGURATION_H

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>

#include "gem/onlinedb/DataSet.h"
#include "gem/onlinedb/DBInterface.h"
#include "gem/onlinedb/PartReference.h"
#include "gem/onlinedb/Run.h"

#include "gem/onlinedb/detail/AMC13ConfigurationGen.h"

namespace gem {
    namespace onlinedb {

        // Forward declaration
        class AMCConfiguration;

        /**
         * @brief Describes the configuration of an AMC13.
         *
         * @note Modifying objects of this class doesn't affect hardware.
         */
        class AMC13Configuration : public detail::AMC13ConfigurationGen
        {
        private:
            std::vector<std::shared_ptr<AMCConfiguration>> m_AMCConfigs;

        public:
            /**
             * @name Child AMC configuration
             * @{
             */
            /**
             * @brief Retrieves the configuration of the given AMC, if set.
             */
            const std::shared_ptr<AMCConfiguration> getAMCConfig(
                std::size_t vfat) const {
                return m_AMCConfigs.at(vfat); };

            /**
             * @brief Retrieves the configuration of the given AMC, if set.
             */
            std::shared_ptr<AMCConfiguration> getAMCConfig(
                std::size_t vfat) {
                return m_AMCConfigs.at(vfat); };

            /**
             * @brief Retrieves the configuration of all AMCs.
             */
            auto getAMCConfigs() const -> const decltype(m_AMCConfigs) & {
                return m_AMCConfigs; };

            /**
             * @brief Retrieves the configuration of all AMCs.
             */
            auto getAMCConfigs() -> decltype(m_AMCConfigs) & { return m_AMCConfigs; };

            /**
             * @brief Modifies the configuration of the given AMC.
             */
            void setAMCConfig(std::size_t amc,
                              const std::shared_ptr<AMCConfiguration> &config) {
                m_AMCConfigs.at(amc) = config; };

            /**
             * @brief Modifies the configuration of all AMCs.
             */
            void setAMCConfigs(const decltype(m_AMCConfigs) &configs) {
                m_AMCConfigs = configs; };

            /**
             * @}
             */
        };

        template<>
        class ConfigurationTraits<AMC13Configuration>:
            public ConfigurationTraits<detail::AMC13ConfigurationGen>
        {
        };

        template<>
        AMC13Configuration DBInterface::convertRow<AMC13Configuration>(
            const xdata::Table &table, xdata::Table::Row &row);
    } /* namespace onlinedb */
} /* namespace gem */

#endif // GEM_ONLINEDB_AMC13CONFIGURATION_H
