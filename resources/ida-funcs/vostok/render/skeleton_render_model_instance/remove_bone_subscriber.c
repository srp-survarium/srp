void __userpurge vostok::render::skeleton_render_model_instance::remove_bone_subscriber(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        _RTL_CRITICAL_SECTION *a2@<esi>,
        vostok::render::update_bones_subscriber *s)
{
  vostok::render::update_bones_subscriber *LockCount; // eax
  vostok::render::update_bones_subscriber *v4; // ecx
  int next; // edx
  int v6; // eax

  if ( a2[1053].LockCount )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)this, a2 + 1052);
    LockCount = (vostok::render::update_bones_subscriber *)a2[1053].LockCount;
    v4 = 0;
    while ( LockCount )
    {
      if ( LockCount == s )
        goto LABEL_7;
      v4 = LockCount;
      LockCount = LockCount->next;
    }
    if ( s )
      goto LABEL_14;
LABEL_7:
    --a2[1051].LockSemaphore;
    next = (int)LockCount->next;
    if ( v4 )
      v4->next = (vostok::render::update_bones_subscriber *)next;
    else
      a2[1053].LockCount = next;
    if ( !LockCount->next )
    {
      v6 = (int)v4;
      if ( !v4 )
        v6 = a2[1053].LockCount;
      a2[1053].RecursionCount = v6;
    }
LABEL_14:
    LeaveCriticalSection(a2 + 1052);
  }
}
