void __userpurge vostok::physics::bt_character_controller::set_landing_callback(
        vostok::physics::bt_character_controller *this@<ecx>,
        _DWORD *a2@<edi>,
        boost::function<void __cdecl(float)> *callback,
        float harmless_fall_heigth)
{
  int v4; // esi
  int v5; // esi

  v4 = *a2;
  boost::function<unsigned char __cdecl (void const *)>::operator=(
    callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)(*a2 + 1192));
  *(_DWORD *)(v4 + 1184) = LODWORD(harmless_fall_heigth) ^ _mask__NegFloat_;
  v5 = a2[1];
  boost::function<unsigned char __cdecl (void const *)>::operator=(
    callback,
    (boost::function1<void,vostok::physics::contact_point const &> *)(v5 + 584));
  *(_DWORD *)(v5 + 576) = LODWORD(harmless_fall_heigth) ^ _mask__NegFloat_;
}
