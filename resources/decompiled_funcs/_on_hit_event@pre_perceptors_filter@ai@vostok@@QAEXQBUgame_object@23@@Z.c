void __thiscall vostok::ai::pre_perceptors_filter::on_hit_event(
        vostok::ai::pre_perceptors_filter *this,
        const vostok::ai::game_object *const hitting_object)
{
  vostok::ai::pre_perceptors_filter::stop_ignoring(this, hitting_object);
}
