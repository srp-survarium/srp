void __thiscall survarium::animations_registry::actualize(
        survarium::animations_registry *this,
        survarium::animations_registry::animations_tuple *__comp)
{
  survarium::animations_registry::animations_tuple *v2; // ebx
  vostok::resources::managed_resource *m_object; // esi
  survarium::animations_registry::animations_tuple *v4; // eax
  survarium::animations_registry::animations_tuple *v5; // ecx
  survarium::animations_registry::animations_tuple *v6; // eax
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> *v7; // ecx
  survarium::animations_registry::animations_tuple *v8; // eax
  survarium::animations_registry::animations_tuple *v9; // edi
  survarium::animations_registry::animations_tuple *v10; // edi
  survarium::animations_registry::animations_tuple *v11; // ebx
  int v12; // eax
  int v13; // ecx
  survarium::animations_registry::animations_tuple v14; // [esp-4h] [ebp-18h]
  vostok::buffer_vector<survarium::animations_registry::animations_tuple> *v15; // [esp-4h] [ebp-18h]
  survarium::animations_registry::animations_tuple *i; // [esp+10h] [ebp-4h] BYREF

  v2 = __comp;
  if ( !LOBYTE(__comp[2].first_view.m_object) )
  {
    m_object = __comp->first_view.m_object;
    LOBYTE(__comp) = 0;
    v4 = (survarium::animations_registry::animations_tuple *)v2->third_view.m_object;
    LOBYTE(v2[2].first_view.m_object) = 1;
    stlp_std::sort<survarium::animations_registry::animations_tuple *,survarium::animations_registry::skeleton_animation_name_less_predicate>(
      (survarium::animations_registry::animations_tuple *)m_object,
      v4,
      0);
    v5 = (survarium::animations_registry::animations_tuple *)v2->third_view.m_object;
    LOBYTE(__comp) = 0;
    v15 = (vostok::buffer_vector<survarium::animations_registry::animations_tuple> *)__comp;
    v6 = (survarium::animations_registry::animations_tuple *)v2->first_view.m_object;
    i = v5;
    __comp = stlp_std::unique<survarium::animations_registry::animations_tuple *,survarium::animations_registry::skeleton_animation_name_equal_predicate>(
               v6,
               (vostok::resources::resource_base *)v5,
               v5);
    vostok::buffer_vector<survarium::animations_registry::animations_tuple>::erase(
      v15,
      (survarium::animations_registry::animations_tuple *const *)v2,
      &__comp,
      &i);
    v8 = (survarium::animations_registry::animations_tuple *)v2->third_view.m_object;
    v9 = (survarium::animations_registry::animations_tuple *)v2->first_view.m_object;
    __comp = 0;
    for ( i = v8; v9 != i; __comp = (survarium::animations_registry::animations_tuple *)((char *)__comp + 1) )
    {
      vostok::buffer_vector<survarium::animations_registry::animations_tuple>::push_back(v7, (int)&v2[1], v9);
      v9->id = (unsigned __int16)__comp;
      ++v9;
    }
    LOBYTE(__comp) = 0;
    v10 = (survarium::animations_registry::animations_tuple *)v2->third_view.m_object;
    v11 = (survarium::animations_registry::animations_tuple *)v2->first_view.m_object;
    if ( v11 != v10 )
    {
      v12 = v10 - v11;
      v13 = 0;
      while ( v12 != 1 )
      {
        ++v13;
        v12 >>= 1;
      }
      stlp_std::priv::__introsort_loop<survarium::animations_registry::animations_tuple *,survarium::animations_registry::animations_tuple,int,survarium::animations_registry::skeleton_animation_predicate>(
        v11,
        v10,
        0,
        2 * v13,
        __comp);
      v14.first_view.m_object = (vostok::resources::managed_resource *)__comp;
      stlp_std::priv::__final_insertion_sort<survarium::animations_registry::animations_tuple *,survarium::animations_registry::skeleton_animation_predicate>(
        v11,
        v10,
        v14);
    }
  }
}
