void __userpurge vostok::animation::mixing::n_ary_tree_cloner::n_ary_tree_cloner(
        vostok::animation::mixing::n_ary_tree_cloner *this@<eax>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *constructor@<edx>,
        unsigned int start_time_in_ms)
{
  this->m_constructor = constructor;
  this->__vftable = (vostok::animation::mixing::n_ary_tree_cloner_vtbl *)&vostok::animation::mixing::n_ary_tree_cloner::`vftable';
  this->m_result = 0;
  this->m_animation_interpolator = 0;
  this->m_interpolators = 0;
  this->m_animation_interval_time = 0;
  this->m_start_time_in_ms = start_time_in_ms;
  this->m_interpolators_count = 0;
  this->m_time_scale_factor = -4.2170408e37;
}
