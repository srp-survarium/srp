void __thiscall vostok::ai::brain_unit::on_sensed_sound(
        vostok::ai::brain_unit *this,
        const vostok::ai::sensors::sensed_object *sound_object)
{
  vostok::ai::subscriptions_manager<vostok::ai::perceptors::sensors_subscriber,vostok::ai::sensors::sensed_object>::on_event(
    &this->m_perceptors_subscriptions_manager,
    sound_object);
}
