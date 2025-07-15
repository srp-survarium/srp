_STLP_atomic_freelist::item *__cdecl stlp_std::__node_alloc_impl::_S_chunk_alloc(unsigned int _p_size, int *__nobjs)
{
  signed int v2; // esi
  _STLP_atomic_freelist::item *v3; // eax
  _STLP_atomic_freelist::item *v4; // ecx
  int v5; // edi
  _STLP_atomic_freelist::item *v6; // ebx
  _STLP_atomic_freelist *v7; // ecx
  unsigned int v8; // edi
  signed int v9; // edi
  int v11; // [esp+0h] [ebp-28h] BYREF
  unsigned int size; // [esp+10h] [ebp-18h]
  _STLP_atomic_freelist::item *v13; // [esp+14h] [ebp-14h]
  int *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v14 = &v11;
  v2 = _p_size * *__nobjs;
  v13 = 0;
  size = v2;
  v3 = (_STLP_atomic_freelist::item *)_STLP_atomic_freelist::pop(&stlp_std::__node_alloc_impl::_S_free_mem_blocks);
  v4 = v3;
  if ( v3 )
  {
    v5 = (char *)v3[1]._M_next - (char *)v3;
    if ( v5 >= v2 )
    {
      v6 = v3;
      v5 -= v2;
      v3 = (_STLP_atomic_freelist::item *)((char *)v3 + v2);
    }
    else if ( v5 < (int)_p_size )
    {
      v6 = v13;
    }
    else
    {
      *__nobjs = v5 / _p_size;
      v2 = _p_size * (v5 / _p_size);
      size = v2;
      v5 %= _p_size;
      v3 = (_STLP_atomic_freelist::item *)((char *)v3 + v2);
      v6 = v4;
    }
    if ( v5 )
    {
      if ( v6 && v5 >= 8 )
      {
        v3[1]._M_next = v4[1]._M_next;
        v7 = &stlp_std::__node_alloc_impl::_S_free_mem_blocks;
      }
      else
      {
        v8 = ((v5 + 8) & 0xFFFFFFF8) - 8;
        if ( !v8 )
          goto LABEL_14;
        v7 = &stlp_std::__node_alloc_impl::_S_free_list[(v8 - 1) >> 3];
      }
      _STLP_atomic_freelist::push(v7, v3);
    }
LABEL_14:
    if ( v6 )
      return v6;
  }
  v9 = ((InterlockedExchangeAdd(&stlp_std::__node_alloc_impl::_S_heap_size, 0) + 7) & 0xFFFFFFF8) + 2 * v2;
  v15 = 0;
  v6 = (_STLP_atomic_freelist::item *)operator new(v9);
  InterlockedExchangeAdd(&stlp_std::__node_alloc_impl::_S_heap_size, v9 >> 4);
  if ( v9 > v2 )
  {
    *(char **)((char *)&v6[1]._M_next + v2) = (char *)v6 + v9;
    _STLP_atomic_freelist::push(
      &stlp_std::__node_alloc_impl::_S_free_mem_blocks,
      (_STLP_atomic_freelist::item *)((char *)v6 + v2));
  }
  return v6;
}
