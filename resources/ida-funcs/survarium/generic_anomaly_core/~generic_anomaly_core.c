void __thiscall survarium::generic_anomaly_core::~generic_anomaly_core(survarium::generic_anomaly_core *this)
{
  vostok::resources::unmanaged_resource *v1; // edi
  survarium::vector<vostok::resources::request> *v2; // ecx

  v1 = &this->vostok::resources::unmanaged_resource;
  this->survarium::link_resolver::__vftable = (survarium::generic_anomaly_core_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::link_resolver'};
  this->survarium::player_actions_subscriber::__vftable = (survarium::player_actions_subscriber_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::player_actions_subscriber'};
  this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::tickable_object::__vftable = (survarium::tickable_object_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::tickable_object'};
  this->survarium::serializable_object::__vftable = (survarium::serializable_object_vtbl *)&survarium::generic_anomaly_core::`vftable'{for `survarium::serializable_object'};
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>((survarium::vector<vostok::resources::request> *)this);
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>(v2);
  vostok::resources::unmanaged_resource::~unmanaged_resource(v1);
}
