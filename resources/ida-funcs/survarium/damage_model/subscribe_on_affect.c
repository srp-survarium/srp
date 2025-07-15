void __thiscall survarium::damage_model::subscribe_on_affect(
        survarium::damage_model *this,
        survarium::hit_affects_type_enum affect_type,
        vostok::ai::perceptors::sensors_subscriber *subscriber)
{
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_affect_subscriptions.elems[affect_type],
    subscriber,
    0);
}
