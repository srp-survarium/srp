void __userpurge vostok::physics::bullet_character_controller::updateAction(
        vostok::physics::bullet_character_controller *this@<ecx>,
        double a2@<st0>,
        btCollisionWorld *collisionWorld,
        float deltaTime)
{
  CProfileNode *Sub_Node; // eax
  char v5; // bl
  vostok::physics::bullet_character_controller *RecursionCounter; // ecx
  void (__cdecl *v8)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v9)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::physics::bullet_character_controller *v10; // ecx
  void (__cdecl *v11)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v12)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  CProfileNode *v13; // ecx
  void (__cdecl *v14)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // edi
  void (__cdecl *v15)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-20h] BYREF

  Sub_Node = CProfileManager::CurrentNode;
  v5 = 0;
  if ( CProfileManager::CurrentNode->Name != "updateAction1" )
  {
    Sub_Node = CProfileNode::Get_Sub_Node((const char *)this);
    CProfileManager::CurrentNode = Sub_Node;
  }
  RecursionCounter = (vostok::physics::bullet_character_controller *)Sub_Node->RecursionCounter;
  ++Sub_Node->TotalCalls;
  Sub_Node->RecursionCounter = (int)&RecursionCounter->__vftable + 1;
  if ( !RecursionCounter )
    Sub_Node->StartTime = btClock::getTimeMicroseconds(0);
  if ( vostok::physics::logging )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", info) )
    {
      v8 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v8 )
      {
        log_callback.functor.obj_ptr = v8;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v5 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bullet_character_controller.cpp",
        0x167u,
        "void __thiscall vostok::physics::bullet_character_controller::updateAction(class btCollisionWorld *,float)",
        "physics:",
        info,
        "updateAction Start  %f %f %f",
        this->m_current_pos.mVec128.m128_f32[0],
        this->m_current_pos.mVec128.m128_f32[1],
        this->m_current_pos.mVec128.m128_f32[2]);
    }
    if ( (v5 & 1) != 0 )
    {
      v5 &= ~1u;
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v9 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v9 )
            v9(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  vostok::physics::bullet_character_controller::pre_step(RecursionCounter, (int)this, a2);
  if ( vostok::physics::logging )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", info) )
    {
      v11 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v11 )
      {
        log_callback.functor.obj_ptr = v11;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v5 |= 2u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bullet_character_controller.cpp",
        0x16Cu,
        "void __thiscall vostok::physics::bullet_character_controller::updateAction(class btCollisionWorld *,float)",
        "physics:",
        info,
        "updateAction Middle %f %f %f",
        this->m_current_pos.mVec128.m128_f32[0],
        this->m_current_pos.mVec128.m128_f32[1],
        this->m_current_pos.mVec128.m128_f32[2]);
    }
    if ( (v5 & 2) != 0 )
    {
      v5 &= ~2u;
      if ( log_callback.vtable )
      {
        if ( ((int)log_callback.vtable & 1) == 0 )
        {
          v12 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
          if ( v12 )
            v12(&log_callback.functor, &log_callback.functor, 2);
        }
      }
    }
  }
  vostok::physics::bullet_character_controller::player_step(v10, (int)this, deltaTime);
  if ( vostok::physics::logging )
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "physics:", info) )
    {
      v14 = vostok::core::g_log_callback;
      log_callback.vtable = 0;
      if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
        `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
          &log_callback.functor,
          &log_callback.functor,
          destroy_functor_tag);
      if ( v14 )
      {
        log_callback.functor.obj_ptr = v14;
        log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                     + 1);
      }
      else
      {
        log_callback.vtable = 0;
      }
      v5 |= 4u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\bullet_character_controller.cpp",
        0x170u,
        "void __thiscall vostok::physics::bullet_character_controller::updateAction(class btCollisionWorld *,float)",
        "physics:",
        info,
        "updateAction Finish %f %f %f",
        this->m_current_pos.mVec128.m128_f32[0],
        this->m_current_pos.mVec128.m128_f32[1],
        this->m_current_pos.mVec128.m128_f32[2]);
    }
    if ( (v5 & 4) != 0 && log_callback.vtable )
    {
      if ( ((int)log_callback.vtable & 1) == 0 )
      {
        v15 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)log_callback.vtable & 0xFFFFFFFE);
        if ( v15 )
          v15(&log_callback.functor, &log_callback.functor, 2);
      }
      log_callback.vtable = 0;
    }
  }
  this->m_walk_vector.mVec128.m128_i32[0] = 0;
  this->m_walk_vector.mVec128.m128_i32[1] = 0;
  this->m_walk_vector.mVec128.m128_i32[2] = 0;
  this->m_walk_vector.mVec128.m128_i32[3] = 0;
  if ( CProfileNode::Return(v13) )
    CProfileManager::CurrentNode = CProfileManager::CurrentNode->Parent;
}
