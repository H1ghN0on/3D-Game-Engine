#pragma once

namespace GameEngine {
	class VertexBuffer {
	public:

		enum class EUsage {
			Static,
			Dynamic,
			Stream
		};

		VertexBuffer(const void* data, const size_t size, const EUsage usage = VertexBuffer::EUsage::Static);
		~VertexBuffer();

		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
		VertexBuffer(VertexBuffer&&) noexcept;
		VertexBuffer& operator=(VertexBuffer&&) noexcept;

		void bind() const;
		static void unbind();
	private:
		unsigned int m_id = 0;
	};
}