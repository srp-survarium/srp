void __fastcall vostok::resources::resource_freeing_functionality::collect_to_free(
        vostok::resources::resource_freeing_functionality *this,
        int a2)
{
  _DWORD *v2; // eax

  v2 = *(_DWORD **)a2;
  this[23].m_collection = 0;
  ++*v2;
  if ( v2[2] )
    *(_DWORD *)(v2[3] + 184) = this;
  else
    v2[2] = this;
  v2[3] = this;
  _InterlockedOr((volatile signed __int32 *)&this[1], 0x20u);
  if ( *(vostok::resources::resources_to_free_collection **)(*(_DWORD *)a2 + 16) == this[11].m_collection )
    *(_DWORD *)(*(_DWORD *)a2 + 20) += this[11].m_data;
}
