void __userpurge survarium::damage_model::unsubscribe_from_damage(
        survarium::damage_model *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<esi>,
        survarium::hit_type_enum damage_type,
        survarium::damage_subscriber *const subscriber)
{
  int LockCount; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax

  if ( a2[49].LockCount )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, a2 + 48);
    LockCount = a2[49].LockCount;
    v5 = 0;
    while ( LockCount )
    {
      if ( LockCount == damage_type )
        goto LABEL_7;
      v5 = LockCount;
      LockCount = *(_DWORD *)(LockCount + 32);
    }
    if ( damage_type )
      goto LABEL_14;
LABEL_7:
    --a2[47].LockSemaphore;
    v6 = *(_DWORD *)(LockCount + 32);
    if ( v5 )
      *(_DWORD *)(v5 + 32) = v6;
    else
      a2[49].LockCount = v6;
    if ( !*(_DWORD *)(LockCount + 32) )
    {
      v7 = v5;
      if ( !v5 )
        v7 = a2[49].LockCount;
      a2[49].RecursionCount = v7;
    }
LABEL_14:
    LeaveCriticalSection(a2 + 48);
  }
}
