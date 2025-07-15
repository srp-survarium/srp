BOOL __thiscall vostok::render::stage_shadow_direct::is_effects_ready(vostok::render::stage_shadow_direct *this)
{
  BOOL result; // eax

  result = 0;
  if ( *(vostok::render::stage_shadow_direct_vtbl **)((char *)&this->__vftable + (_DWORD)&loc_4016F + 1) )
    return *(_DWORD *)((char *)&loc_40174 + (_DWORD)this) != 0;
  return result;
}
