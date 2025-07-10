void __userpurge survarium::game_world::finish_npc_creation(
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *new_npc@<ecx>,
        survarium::human_npc::npc_game_attributes *attributes@<eax>,
        survarium::game_world *this)
{
  survarium::human_npc *v4; // ecx
  vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v5; // ecx
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-Ch] BYREF

  survarium::human_npc::set_attributes(new_npc->m_object, attributes);
  survarium::human_npc::enable(v4, (int)new_npc->m_object);
  v6.m_object = 0;
  vostok::intrusive_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    new_npc);
  vostok::intrusive_list<survarium::human_npc,vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base>,320,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    v5,
    &this->m_npcs,
    (bool *)v6.m_object);
}
