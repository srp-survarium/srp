void __userpurge survarium::player_logic_preview_state::player_logic_preview_state(
        survarium::player_logic_preview_state *this@<esi>,
        survarium::weapon_user_animations_selector *owner@<eax>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  survarium::player_logic_base_state::player_logic_base_state(this, owner, type_preview);
  this->__vftable = (survarium::player_logic_preview_state_vtbl *)result.m_buffer;
  this->m_animations = animations;
  this->m_animations_count = animations_count;
  this->m_random.m_seed = 0;
}
