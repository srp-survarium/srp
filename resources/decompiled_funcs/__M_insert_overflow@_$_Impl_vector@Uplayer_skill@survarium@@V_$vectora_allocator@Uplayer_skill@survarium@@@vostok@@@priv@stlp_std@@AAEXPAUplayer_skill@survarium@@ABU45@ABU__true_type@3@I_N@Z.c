void __userpurge stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_insert_overflow(
        stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill> > *this@<ecx>,
        unsigned __int8 **a2@<esi>,
        int __pos,
        const survarium::player_skill *__x,
        const stlp_std::__true_type *__formal,
        unsigned int __fill_len,
        bool __atend)
{
  survarium::player_skill *v7; // ebx
  unsigned int size; // ebp
  int *p_pos; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  survarium::player_skill *v13; // eax
  survarium::player_skill *v14; // ebx
  unsigned int v15; // [esp+0h] [ebp-10h]
  unsigned int v16; // [esp+Ch] [ebp-4h] BYREF

  v7 = (survarium::player_skill *)__pos;
  size = stlp_std::priv::_Impl_vector<survarium::player_skill,vostok::vectora_allocator<survarium::player_skill>>::_M_compute_next_size(
           this,
           v15);
  v16 = size;
  __pos = 1;
  p_pos = &__pos;
  if ( size )
    p_pos = (int *)&v16;
  v10 = (unsigned __int8 *)(*(int (__thiscall **)(unsigned __int8 *, _DWORD, int))(*(_DWORD *)a2[2] + 20))(
                             a2[2],
                             0,
                             2 * *p_pos);
  v11 = (char *)v7 - (char *)*a2;
  if ( v11 )
  {
    memmove(v10, *a2, v11);
    v13 = (survarium::player_skill *)(v11 + v12);
  }
  else
  {
    v13 = (survarium::player_skill *)v10;
  }
  *v13 = *__x;
  v14 = v13 + 1;
  (*(void (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)a2[2] + 24))(a2[2], *a2);
  *a2 = v10;
  a2[1] = &v14->skill_id;
  a2[3] = &v10[2 * size];
}
