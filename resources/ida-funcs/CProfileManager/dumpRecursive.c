void __cdecl CProfileManager::dumpRecursive(CProfileIterator *profileIterator, int spacing)
{
  btClock *v2; // ecx
  CProfileNode *Child; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // ebx
  int v7; // ebx
  float TotalTime; // xmm1_4
  float v9; // xmm0_4
  CProfileNode *Sibling; // eax
  float v11; // xmm1_4
  int v12; // ebx
  float v13; // xmm0_4
  int v14; // ebx
  int v15; // edi
  CProfileNode *v16; // ecx
  int v17; // eax
  CProfileNode *v18; // ecx
  CProfileNode *CurrentChild; // eax
  CProfileNode *Parent; // eax
  float parent_time; // [esp+38h] [ebp-41Ch]
  float accumulated_time; // [esp+3Ch] [ebp-418h]
  int fraction; // [esp+40h] [ebp-414h]
  int numChildren; // [esp+44h] [ebp-410h]
  char buffer[1024]; // [esp+54h] [ebp-400h] BYREF

  Child = profileIterator->CurrentParent->Child;
  profileIterator->CurrentChild = Child;
  if ( Child )
  {
    accumulated_time = 0.0;
    if ( profileIterator->CurrentParent->Parent )
      parent_time = profileIterator->CurrentParent->TotalTime;
    else
      parent_time = (double)((unsigned int)btClock::getTimeMicroseconds(v2) - CProfileManager::ResetTime) * 0.001;
    v4 = spacing;
    fraction = CProfileManager::FrameCounter;
    if ( spacing > 0 )
    {
      v5 = spacing;
      do
      {
        printf((const char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
        --v5;
      }
      while ( v5 );
    }
    sprintf(buffer, (const char *)&stru_957BE0.vostok::resources::resource_flags + 12);
    physics_log_fn(buffer);
    if ( spacing > 0 )
    {
      v6 = spacing;
      do
      {
        printf((const char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
        --v6;
      }
      while ( v6 );
    }
    sprintf(buffer, &stru_957BE0.m_children_resources.gapC, profileIterator->CurrentParent->Name, parent_time);
    physics_log_fn(buffer);
    v7 = 0;
    numChildren = 0;
    if ( profileIterator->CurrentChild )
    {
      do
      {
        TotalTime = profileIterator->CurrentChild->TotalTime;
        ++numChildren;
        accumulated_time = TotalTime + accumulated_time;
        if ( parent_time <= 0.00000011920929 )
          v9 = 0.0;
        else
          v9 = (float)(TotalTime / parent_time) * 100.0;
        if ( v4 > 0 )
        {
          do
          {
            printf((const char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
            --v4;
          }
          while ( v4 );
          v4 = spacing;
        }
        sprintf(
          buffer,
          (const char *)&stru_957BE0.m_current_satisfaction_update_tick + 4,
          v7,
          profileIterator->CurrentChild->Name,
          v9,
          TotalTime / (double)fraction,
          profileIterator->CurrentChild->TotalCalls);
        physics_log_fn(buffer);
        Sibling = profileIterator->CurrentChild->Sibling;
        ++v7;
        profileIterator->CurrentChild = Sibling;
      }
      while ( Sibling );
    }
    v11 = parent_time;
    if ( accumulated_time > parent_time )
    {
      printf((const char *)&stru_957BE0.m_next_in_memory_type);
      v11 = parent_time;
    }
    if ( v4 > 0 )
    {
      v12 = v4;
      do
      {
        printf((const char *)&stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags);
        --v12;
      }
      while ( v12 );
      v11 = parent_time;
    }
    if ( v11 <= 0.00000011920929 )
      v13 = 0.0;
    else
      v13 = (float)((float)(v11 - accumulated_time) / v11) * 100.0;
    sprintf(
      buffer,
      (const char *)&stru_957BE0.m_next_for_grm_observer_list,
      &stru_957BE0.m_fat_it.m_link_target,
      v13,
      (float)(v11 - accumulated_time));
    physics_log_fn(buffer);
    v14 = 0;
    if ( numChildren > 0 )
    {
      v15 = v4 + 3;
      do
      {
        v16 = profileIterator->CurrentParent->Child;
        v17 = v14;
        profileIterator->CurrentChild = v16;
        if ( v16 )
        {
          do
          {
            if ( !v17 )
              break;
            v18 = profileIterator->CurrentChild->Sibling;
            --v17;
            profileIterator->CurrentChild = v18;
          }
          while ( v18 );
        }
        CurrentChild = profileIterator->CurrentChild;
        if ( CurrentChild )
        {
          profileIterator->CurrentParent = CurrentChild;
          profileIterator->CurrentChild = CurrentChild->Child;
        }
        CProfileManager::dumpRecursive(profileIterator, v15);
        Parent = profileIterator->CurrentParent->Parent;
        if ( Parent )
          profileIterator->CurrentParent = Parent;
        ++v14;
        profileIterator->CurrentChild = profileIterator->CurrentParent->Child;
      }
      while ( v14 < numChildren );
    }
  }
}
