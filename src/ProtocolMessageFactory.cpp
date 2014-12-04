#include "ProtocolMessageFactory.h"
#include "IProtocolMessage.h"

namespace ai {

ProtocolMessageFactory::ProtocolMessageFactory() {
}

bool ProtocolMessageFactory::isNewMessageAvailable(const streamContainer& in) const {
	const int32_t size = IProtocolMessage::peekInt(in);
	if (size == -1) {
		// not enough data yet, wait a little bit more
		return false;
	}
	const int streamSize = static_cast<int>(in.size() - sizeof(int32_t));
	if (size > streamSize) {
		// not enough data yet, wait a little bit more
		return false;
	}
	return true;
}

IProtocolMessage *ProtocolMessageFactory::create(streamContainer& in) {
	// remove the size from the stream
	in.erase(in.begin(), in.begin() + sizeof(int32_t));
	// get the message type
	const uint8_t type = in.front();
	in.pop_front();
	switch (type) {
	default:
		// TODO autogenerate
		break;
	}

	return nullptr;
}

}
