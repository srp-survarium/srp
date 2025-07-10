void __thiscall vostok::sound::world_user::~world_user(vostok::sound::world_user *this)
{
  vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>>::owner_finalize((vostok::one_way_threads_channel<vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4>,vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> > *)this);
  vostok::sound::two_way_threads_channel::~two_way_threads_channel(&this->m_channel);
}
