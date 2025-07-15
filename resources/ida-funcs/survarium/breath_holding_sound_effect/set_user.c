void __usercall survarium::breath_holding_sound_effect::set_user(
        survarium::breath_holding_sound_effect *this@<ecx>,
        vostok::sound::sound_instance_proxy *a2@<esi>)
{
  vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy> *v2; // ecx

  if ( a2->__vftable )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      (*((void (__thiscall **)(vostok::sound::sound_instance_proxy_vtbl *))a2->play + 3))(a2->__vftable);
      vostok::intrusive_ptr<vostok::sound::sound_instance_proxy,vostok::sound::sound_instance_proxy,vostok::threading::single_threading_policy>::operator=(
        v2,
        a2);
    }
  }
}
