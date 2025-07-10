void __thiscall vostok::sound::world_user::add_response(
        vostok::sound::world_user *this,
        vostok::sound::sound_response *response)
{
  vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::push_back(
    (vostok::intrusive_spsc_queue<vostok::sound::sound_order,vostok::sound::sound_order,4> *)this,
    (vostok::sound::sound_order *const)response);
}
