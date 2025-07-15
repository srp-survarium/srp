BOOL __usercall vostok::physics::old_bullet_character_controller::can_stand@<eax>(
        vostok::physics::old_bullet_character_controller *this@<ecx>,
        int a2@<eax>,
        vostok::physics::character_controller_sweep_test_cache_template<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type>::cache_predicate a3@<edi>,
        const stlp_std::random_access_iterator_tag *a4@<esi>)
{
  return !*(_DWORD *)(a2 + 20)
      || !*(_BYTE *)(a2 + 560)
      || vostok::physics::character_controller_can_stand_tester::can_stand(
           (vostok::physics::character_controller_can_stand_tester *)(a2 + 224),
           a3,
           a4,
           (stlp_std::pair<vostok::physics::character_controller_can_stand_tester::key_type,vostok::physics::character_controller_can_stand_tester::value_type> *)(a2 + 4896),
           (float *)(a2 + 224));
}
