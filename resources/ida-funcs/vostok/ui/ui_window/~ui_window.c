void __thiscall vostok::ui::ui_window::~ui_window(vostok::ui::ui_window *this)
{
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v2; // ecx
  stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers> > *v3; // ecx

  this->__vftable = (vostok::ui::ui_window_vtbl *)&vostok::ui::ui_window::`vftable';
  vostok::ui::ui_window::remove_all_children(this);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v2,
    (int)&this->m_children);
  stlp_std::priv::_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>::~_Impl_vector<vostok::ui::typed_handlers,vostok::vectora_allocator<vostok::ui::typed_handlers>>(v3);
}
