# Ring

Resizable ring data structure: `class Ring<T, Allocator>`.

Uses `std::vector<T, Allocator>` under the hood.

The Ring class is a contiguous container that stores data on the heap, has predetermined size, and accepts insertions in a cyclic fashion: when the container is full, it starts over at the beginning and overwrites the oldest data.

Typical uses include download buffer or history container.


## API

Some methods are presented here, for a full list please see the source file.

```
push_back(T)
```
Insert an item after the last inserted one. If the ring is full (i.e. `item_count() == size()`), the insertion happens anyway and overwrites the oldest contained item.

```
size() const -> size_t
```
Ring's size, i.e. how many items it can store. Note that a full ring still accepts insertions (see push_back).

```
item_count() const -> size_t
```
The number of items actually contained at present.
In typical usage, `item_count()` will be equal to `size()` most of the time, but not always.

```
extract_data() const -> std::vector<T, Alloc>
```
Get a copy of the contained data in a new vector. This vector is correctly rotated, so the oldest item is at index 0. And its size is equal to `item_count()`. Doesn't modify internal storage.

```
rotate_data()
```
This method directly mutate the internal storage, by applying a rotation so that the oldest item of data ends up at index 0 of internal storage.

```
storage() const -> Internal_storage
storage()       -> Internal_storage
```
This method returns an object that serves mostly as a view on the underlying storage vector. It enables the user to query unrotated data.

The mutable version of `Internal_storage` has a proxy to the `shrink_to_fit()` method of `std::vector`, in case you want to use it after construction or a resize. This being accessible in this view class serves mostly the purpose of avoiding confusion with a method that would resize the ring to its content size. This would be achieved here by calling `ring.resize(ring.item_count())`.
