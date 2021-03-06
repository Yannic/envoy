#pragma once

#include "envoy/config/trace/v2alpha/xray.pb.h"
#include "envoy/config/trace/v2alpha/xray.pb.validate.h"

#include "common/common/logger.h"

#include "extensions/tracers/common/factory_base.h"

namespace Envoy {
namespace Extensions {
namespace Tracers {
namespace XRay {

/**
 * Config registration for the XRay tracer. @see TracerFactory.
 */
class XRayTracerFactory : public Common::FactoryBase<envoy::config::trace::v2alpha::XRayConfig>,
                          Logger::Loggable<Logger::Id::tracing> {
public:
  XRayTracerFactory();

private:
  Tracing::HttpTracerPtr
  createHttpTracerTyped(const envoy::config::trace::v2alpha::XRayConfig& proto_config,
                        Server::Instance& server) override;
};

} // namespace XRay
} // namespace Tracers
} // namespace Extensions
} // namespace Envoy
