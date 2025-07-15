const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *__usercall survarium::game_world::get_project@<eax>(
        survarium::game_world *this@<ecx>,
        vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>)
{
  vostok::resources::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::server_game_project,vostok::resources::unmanaged_intrusive_base>(
    a2,
    &this->m_game_project);
  return (const vostok::resources::resource_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base> *)a2;
}
