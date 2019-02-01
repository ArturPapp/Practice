#pragma once

#include <memory>

namespace apapp
{
	namespace std
	{
		template<class T, class Allocator = std::allocator<T>>
		class vector {
			typedef value_type T;
			typedef allocator_type Allocator;
			typedef size_type size_t;
			typedef difference_type std::ptrdiff_t;
			typedef reference value_type&;
			typedef const_reference const value_type&;
			typedef pointer std::allocator_traits<Allocator>::pointer;
			typedef const_pointer std::allocator_traits<Allocator>::const_pointer;
			//typedef iterator LegacyRandomAccessIterator;
			//typedef const_iterator Constant LegacyRandomAccessIterator;
			//typedef reverse_iterator std::reverse_iterator<iterator>;
			//typedef const_reverse_iterator std::reverse_iterator<const_iterator>;

		private:
			pointer _start_data;
			pointer _end_data;
			pointer _end_allocate;
		public:
			vector() noexcept(noexcept(Allocator()));
			explicit vector(const Allocator& alloc) noexcept;
			vector(size_type count,	const T& value, const Allocator& alloc = Allocator());
			explicit vector(size_type count, const Allocator& alloc = Allocator());
			template< class InputIt >
			vector(InputIt first, InputIt last,	const Allocator& alloc = Allocator());
			vector(const vector& other);
			vector(const vector& other, const Allocator& alloc);
			vector(vector&& other) noexcept;
			vector(vector&& other, const Allocator& alloc);
			vector(std::initializer_list<T> init,	const Allocator& alloc = Allocator());

			virtual ~vector();

			vector& operator=(const vector& other);
			vector& operator=(vector&& other) noexcept;
			vector& operator=(std::initializer_list<T> initlist);

			void assign(size_type count, const T& value);
			template< class InputIt >
			void assign(InputIt first, InputIt last);
			void assign(std::initializer_list<T> initlist);

			allocator_type get_allocator() const;

			//Element access
			reference       at(size_type pos);
			const_reference at(size_type pos) const;

			reference       operator[](size_type pos);
			const_reference operator[](size_type pos) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;

			T* data() noexcept;
			const T* data() const noexcept;

			//Iterators
			iterator begin() noexcept;
			const_iterator begin() const noexcept;
			const_iterator cbegin() const noexcept;

			iterator end() noexcept;
			const_iterator end() const noexcept;
			const_iterator cend() const noexcept;

			reverse_iterator rbegin() noexcept;
			const_reverse_iterator rbegin() const noexcept;
			const_reverse_iterator crbegin() const noexcept;

			reverse_iterator rend() noexcept;
			const_reverse_iterator rend() const noexcept;
			const_reverse_iterator crend() const noexcept;

			//Capacity
			bool empty() const noexcept; //(until C++20)
			[[nodiscard]] bool empty() const noexcept;

			size_type size() const noexcept;
			size_type max_size() const noexcept;

			void reserve(size_type new_cap);

			size_type capacity() const noexcept;

			void shrink_to_fit();

			//Modifiers
			void clear() noexcept;
			iterator insert(const_iterator pos, const T& value);
			iterator insert(const_iterator pos, T&& value);
			iterator insert(const_iterator pos, size_type count, const T& value);
			template< class InputIt >
			iterator insert(const_iterator pos, InputIt first, InputIt last);
			iterator insert(const_iterator pos, std::initializer_list<T> ilist);

			template< class... Args >
			iterator emplace(const_iterator pos, Args&&... args);

			iterator erase(const_iterator pos);
			iterator erase(const_iterator first, const_iterator last);

			void push_back(const T& value);
			void push_back(T&& value);

			template< class... Args >
			reference emplace_back(Args&&... args);

			void pop_back();

			void resize(size_type count);
			void resize(size_type count, const value_type& value);

			void swap(vector& other) noexcept;
		};
	}
}