#pragma once

namespace er {

	struct Timestep
	{
	public:
		inline Timestep(float initialTime = 0.0f)
			: m_Timestep(0.0f), m_LastTime(initialTime)
		{
		}

		inline void Update(float currentTime)
		{
			m_Timestep = currentTime - m_LastTime;
			m_LastTime = currentTime;
		}

		operator float() const { return m_Timestep; }

		inline float GetMillis() const { return m_Timestep * 1000.0f; }
		inline float GetSeconds() const { return m_Timestep; }
	private:
		float m_Timestep;
		float m_LastTime;
	};
}