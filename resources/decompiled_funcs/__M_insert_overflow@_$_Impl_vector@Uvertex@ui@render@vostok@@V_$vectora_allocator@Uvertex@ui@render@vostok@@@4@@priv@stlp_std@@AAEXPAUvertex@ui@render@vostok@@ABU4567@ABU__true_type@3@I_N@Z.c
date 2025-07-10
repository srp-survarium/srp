void __userpurge stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        vostok::render::ui::vertex *__pos,
        const D3D11_INPUT_ELEMENT_DESC *__x,
        unsigned int __formal,
        unsigned int __fill_len,
        bool __atend)
{
  const stlp_std::__true_type *v7; // ebp
  unsigned int *p_formal; // eax
  unsigned __int8 *v9; // ebx
  char *v10; // edi
  int v11; // eax
  D3D11_INPUT_ELEMENT_DESC *v12; // eax
  unsigned __int8 *v13; // ebp
  unsigned int v14; // edi
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-8h] BYREF
  unsigned int size; // [esp+10h] [ebp-4h]

  v7 = (const stlp_std::__true_type *)__formal;
  size = stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::_M_compute_next_size(
           (stlp_std::priv::_Impl_vector<D3D11_INPUT_ELEMENT_DESC,vostok::render::std_allocator<D3D11_INPUT_ELEMENT_DESC> > *)this,
           __formal);
  v17 = size;
  __formal = 1;
  p_formal = &__formal;
  if ( size )
    p_formal = &v17;
  v9 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, unsigned int))(*(_DWORD *)a2[2] + 20))(
                            a2[2],
                            0,
                            28 * *p_formal);
  v10 = (char *)((char *)__pos - (char *)*a2);
  if ( __pos == (vostok::render::ui::vertex *)*a2 )
  {
    v12 = (D3D11_INPUT_ELEMENT_DESC *)v9;
  }
  else
  {
    memmove(v9, *a2, (char *)__pos - (char *)*a2);
    v12 = (D3D11_INPUT_ELEMENT_DESC *)&v10[v11];
  }
  v13 = (unsigned __int8 *)stlp_std::priv::__fill_n<vostok::render::ui::vertex *,unsigned int,vostok::render::ui::vertex>(
                             v12,
                             (unsigned int)v7,
                             __x);
  v14 = a2[1] - (unsigned __int8 *)__pos;
  if ( v14 )
  {
    memmove(v13, (unsigned __int8 *)__pos, v14);
    v13 = (unsigned __int8 *)(v14 + v15);
  }
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  v16 = 7 * size;
  a2[1] = v13;
  *a2 = v9;
  a2[3] = &v9[4 * v16];
}
