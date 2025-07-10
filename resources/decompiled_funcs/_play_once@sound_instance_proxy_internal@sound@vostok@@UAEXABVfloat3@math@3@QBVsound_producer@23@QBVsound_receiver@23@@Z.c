void __thiscall vostok::sound::sound_instance_proxy_internal::play_once(
        vostok::sound::sound_instance_proxy_internal *this,
        const vostok::math::float3 *position,
        const vostok::sound::sound_producer *const producer,
        const vostok::sound::sound_receiver *const ignorable_receiver)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> v4; // [esp-14h] [ebp-E8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > > > v5; // [esp-10h] [ebp-E4h] BYREF
  signed __int64 v6; // [esp+8h] [ebp-CCh]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > > > *v7; // [esp+10h] [ebp-C4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> > > > *result; // [esp+14h] [ebp-C0h]
  vostok::sound::sound_instance_proxy_internal *thisa; // [esp+18h] [ebp-BCh]
  signed __int64 v10; // [esp+1Ch] [ebp-B8h]
  vostok::sound::atomic_half3 *p_m_position; // [esp+24h] [ebp-B0h]
  signed __int64 m_atomic; // [esp+28h] [ebp-ACh]
  vostok::sound::atomic_half3 v13; // [esp+48h] [ebp-8Ch] BYREF
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v14; // [esp+A0h] [ebp-34h]
  vostok::math::half3 v15; // [esp+BEh] [ebp-16h] BYREF
  void (__thiscall *__ptr64 f)(vostok::sound::sound_instance_proxy_internal *, vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>); // [esp+C4h] [ebp-10h]

  thisa = this;
  LODWORD(f) = vostok::sound::sound_instance_proxy_internal::on_finish_callback;
  HIDWORD(f) = 0;
  result = &v5;
  v14 = &v4;
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::set(
    &v4,
    this);
  v7 = boost::bind<void,vostok::sound::sound_instance_proxy_internal,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>,vostok::sound::sound_instance_proxy_internal *,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>(
         result,
         f,
         thisa,
         v4);
  boost::function<void __cdecl (void)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_instance_proxy_internal,vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>>>>>(
    &thisa->m_callback,
    v5);
  _InterlockedExchange(&thisa->m_is_playing_once, 1);
  vostok::math::half3::half3(&v15, position);
  vostok::sound::atomic_half3::atomic_half3(&v13);
  v13.m_data.m_val = v15.vostok::math::half3_pod;
  v10 = __PAIR64__(HIDWORD(v13.m_data.m_atomic), *(unsigned int *)&v15.x.data);
  p_m_position = &thisa->m_position;
  do
  {
    m_atomic = p_m_position->m_data.m_atomic;
    v6 = _InterlockedCompareExchange64((volatile signed __int64 *)p_m_position, v10, m_atomic);
  }
  while ( v6 != m_atomic );
  thisa->play(thisa, once, producer, ignorable_receiver);
}
