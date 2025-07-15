void __thiscall survarium::bullet_manager::update_tracer(
        survarium::bullet_manager *this,
        survarium::bullet *bullet,
        const vostok::math::float3 *position,
        const vostok::math::float3 *direction,
        float *length,
        int a6)
{
  survarium::bullet_manager::bullet_functor *v6; // ebx
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *v7; // ecx
  survarium::bullet_manager::bullet_functor *v8; // eax
  vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76> *v9; // ecx
  _BYTE v10[28]; // [esp-1Ch] [ebp-58h] BYREF
  _DWORD v11[6]; // [esp+Ch] [ebp-30h] BYREF
  _DWORD v12[5]; // [esp+24h] [ebp-18h] BYREF

  v6 = 0;
  if ( *(_DWORD *)&bullet->m_ricochet_count )
  {
    type_info::raw_name(&survarium::bullet_manager::bullet_functor `RTTI Type Descriptor');
    v8 = vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::try_pop(
           v7,
           (volatile signed __int64 *)&bullet->m_start_position.elements[1]);
    if ( v8 )
    {
      v8->functor.vtable = 0;
      v8->resource.m_object = 0;
      v6 = v8;
    }
    v6->position = *direction;
    v6->direction.x = *length;
    v6->direction.y = length[1];
    v12[3] = &v6->direction;
    v6->direction.z = length[2];
    v12[0] = bullet;
    v12[2] = &v6->position;
    v12[1] = position;
    v12[4] = a6;
    v11[0] = survarium::bullet_manager::update_tracer_impl;
    qmemcpy(&v11[1], v12, 0x14u);
    *(_DWORD *)v10 = v6;
    qmemcpy(&v10[4], v11, 0x18u);
    boost::function<void __cdecl (void)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,survarium::bullet *,vostok::math::float3 const &,vostok::math::float3 const &,float>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<survarium::bullet *>,boost::reference_wrapper<vostok::math::float3 const>,boost::reference_wrapper<vostok::math::float3 const>,boost::_bi::value<float>>>>(
      0,
      *(boost::_bi::bind_t<void,boost::_mfi::mf4<void,survarium::bullet_manager,survarium::bullet *,vostok::math::float3 const &,vostok::math::float3 const &,float>,boost::_bi::list5<boost::_bi::value<survarium::bullet_manager *>,boost::_bi::value<survarium::bullet *>,boost::reference_wrapper<vostok::math::float3 const >,boost::reference_wrapper<vostok::math::float3 const >,boost::_bi::value<float> > > *)v10,
      *(int *)&v10[24]);
    vostok::intrusive_mpmc_stack<survarium::bullet_manager::bullet_functor,survarium::bullet_manager::bullet_functor,76>::push(
      v9,
      (int)&bullet->m_start_velocity.z,
      v6);
  }
}
