void __thiscall vostok::physics::bullet_physics_world::notify_about_contact(
        vostok::physics::bullet_physics_world *this,
        vostok::physics::bullet_physics_world *thisa)
{
  vostok::physics::bullet_physics_world *v2; // ebx
  int v3; // eax
  int v4; // edx
  btPersistentManifold *v5; // eax
  int m_cachedPoints; // edx
  int v7; // ecx
  float *m128_f32; // edi
  vostok::physics::base_physics_object *v9; // esi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // edx
  stlp_std::priv::_Rb_tree_node_base *p_M_data; // ecx
  stlp_std::priv::_Rb_tree_node_base *v12; // eax
  stlp_std::priv::_Rb_tree_node_base *v13; // ebx
  stlp_std::priv::_Rb_tree_node_base *v14; // eax
  stlp_std::priv::_Rb_tree_node_base *v15; // esi
  stlp_std::priv::_Rb_tree_node_base *v16; // edi
  survarium::game_camera *v17; // eax
  float *v18; // [esp+10h] [ebp-130h]
  int i; // [esp+14h] [ebp-12Ch]
  vostok::physics::base_physics_object *base_obj_a; // [esp+18h] [ebp-128h]
  int num_manifolds; // [esp+1Ch] [ebp-124h]
  vostok::physics::base_physics_object *base_obj_b; // [esp+20h] [ebp-120h]
  _DWORD v23[3]; // [esp+24h] [ebp-11Ch] BYREF
  boost::bad_function_call v24; // [esp+30h] [ebp-110h] BYREF

  v2 = thisa;
  v3 = thisa->m_dispatcher->getNumManifolds(thisa->m_dispatcher);
  v4 = 0;
  num_manifolds = v3;
  i = 0;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      v5 = v2->m_dispatcher->getManifoldByIndexInternal(v2->m_dispatcher, v4);
      m_cachedPoints = v5->m_cachedPoints;
      v7 = 0;
      if ( m_cachedPoints > 0 )
      {
        m128_f32 = v5->m_pointCache[0].m_localPointA.mVec128.m128_f32;
        while ( m128_f32[20] >= 0.0 )
        {
          ++v7;
          m128_f32 += 72;
          if ( v7 >= m_cachedPoints )
            goto LABEL_25;
        }
        v9 = (vostok::physics::base_physics_object *)*((_DWORD *)v5->m_body0 + 62);
        M_parent = v2->m_contact_callbacks._M_t._M_header._M_data._M_parent;
        p_M_data = &v2->m_contact_callbacks._M_t._M_header._M_data;
        base_obj_b = (vostok::physics::base_physics_object *)*((_DWORD *)v5->m_body1 + 62);
        v12 = M_parent;
        v18 = m128_f32;
        base_obj_a = v9;
        v13 = &v2->m_contact_callbacks._M_t._M_header._M_data;
        while ( v12 )
        {
          if ( (unsigned int)v9 >= *(_DWORD *)&v12[1]._M_color )
          {
            v12 = v12->_M_right;
          }
          else
          {
            v13 = v12;
            v12 = v12->_M_left;
          }
        }
        v14 = M_parent;
        while ( v14 )
        {
          if ( *(_DWORD *)&v14[1]._M_color < (unsigned int)v9 )
          {
            v14 = v14->_M_right;
          }
          else
          {
            p_M_data = v14;
            v14 = v14->_M_left;
          }
        }
        v15 = p_M_data;
        if ( p_M_data != v13 )
        {
          while ( 1 )
          {
            *(float *)v23 = m128_f32[12];
            *(float *)&v23[1] = m128_f32[13];
            *(float *)&v23[2] = -m128_f32[14];
            v16 = v15[1]._M_parent;
            if ( !*(_DWORD *)&v16->_M_color )
            {
              boost::bad_function_call::bad_function_call(&v24);
              boost::throw_exception(v17);
              stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v24);
            }
            (*(void (__cdecl **)(stlp_std::priv::_Rb_tree_node_base **, vostok::physics::base_physics_object *, vostok::physics::base_physics_object *, _DWORD *))((*(_DWORD *)&v16->_M_color & 0xFFFFFFFE) + 4))(
              &v16->_M_left,
              base_obj_a,
              base_obj_b,
              v23);
            v15 = stlp_std::priv::_Rb_global<bool>::_M_increment(v15);
            if ( v15 == v13 )
              break;
            m128_f32 = v18;
          }
        }
      }
LABEL_25:
      v4 = ++i;
      if ( i >= num_manifolds )
        break;
      v2 = thisa;
    }
  }
}
