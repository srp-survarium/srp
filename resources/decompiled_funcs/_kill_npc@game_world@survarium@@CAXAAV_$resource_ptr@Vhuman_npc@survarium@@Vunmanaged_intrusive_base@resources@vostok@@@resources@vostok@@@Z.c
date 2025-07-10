void __usercall survarium::game_world::kill_npc(
        vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *condemned@<esi>)
{
  vostok::resources::resource_ptr<survarium::human_npc,vostok::resources::unmanaged_intrusive_base> *v1; // [esp+0h] [ebp-4h]

  survarium::delete_weapons(v1);
  condemned->m_object->clear_resources(condemned->m_object);
}
