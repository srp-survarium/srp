void __thiscall survarium::items_dictionary::items_dictionary(survarium::items_dictionary *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->dict_config);
  this->__vftable = (survarium::items_dictionary_vtbl *)&survarium::items_dictionary::`vftable';
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->dict_config);
  stlp_std::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>::map<unsigned int,vostok::ai::planning::pddl_predicate *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::pddl_predicate *>>>((stlp_std::map<unsigned int,vostok::ai::planning::oracle *,stlp_std::less<unsigned int>,vostok::ai::std_allocator<stlp_std::pair<unsigned int,vostok::ai::planning::oracle *> > > *)&this->m_items_dict);
}
