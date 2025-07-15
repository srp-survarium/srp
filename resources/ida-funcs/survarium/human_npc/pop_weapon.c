survarium::object_weapon *__usercall survarium::human_npc::pop_weapon@<eax>(
        survarium::human_npc *this@<ecx>,
        int a2@<eax>)
{
  return vostok::intrusive_list<vostok::render::frame_histogram_info,vostok::render::frame_histogram_info *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_front(
           (vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)this,
           a2 + 360);
}
