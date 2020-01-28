#pragma once

#include "er/core/Types.h"

namespace er {

	struct Members;

	class Timer
	{
	private:
		byte m_Reserved[32];
		Members* m_Members;
	public:
		Timer();						// Creates and starts timer

		virtual void Reset();			// Resets the time
		virtual float Elapsed();		// Returns time in seconds
		virtual float ElapsedMillis();	// Returns time in milliseconds
	};

}