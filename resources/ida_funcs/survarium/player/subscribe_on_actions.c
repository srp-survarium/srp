void __thiscall survarium::player::subscribe_on_actions(
        survarium::player *this,
        survarium::player_actions_subscriber *subscriber)
{
  void **v2; // eax
  unsigned __int8 **v3; // edi
  bool v4; // [esp+0h] [ebp-4h]

  v2 = *(void ***)((char *)&dword_10DDC + (_DWORD)this);
  v3 = (unsigned __int8 **)((char *)&dword_10DD8 + (_DWORD)this);
  if ( v2 == *(void ***)((char *)&dword_10DE0 + (_DWORD)this) )
  {
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)this,
      v3,
      v2,
      (void *const *)&subscriber,
      (const stlp_std::__true_type *)1,
      1,
      v4);
  }
  else
  {
    *v2 = subscriber;
    v3[1] += 4;
  }
}
