#pragma once

#include <memory>

namespace apapp
{
	template<class T, class Allocator = std::allocator<T>>
	class vector {
		vector();
		virtual ~vector();

		vector& operator=(const vector& other);
		vector& operator=(vector&& other);
		//vector& operator=(vector&& other) noexcept(/* see below */);
		vector& operator=(std::initializer_list<T> initlist);

		void assign(size_type count, const T& value);
		template< class InputIt >
		void assign(InputIt first, InputIt last);
		void assign(std::initializer_list<T> initlist);

		allocator_type get_allocator() const;

		T& at(size_type pos);
		const T& at(size_type pos) const;

		T& operator[](size_type pos);
		const T& operator[](size_type pos) const;

		T& front();
		const T& front() const;

		T& back();
		const T& back() const;

		T* data() noexcept;
		const T* data() const noexcept;
	};

	template<bool, class Allocator = std::allocator<T>>
	class vector {

	};
}