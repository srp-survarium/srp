void __thiscall boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1>>>::operator()<vostok::ai::brain_unit const *>(
        boost::_bi::bind_t<void,boost::_mfi::cmf0<void,vostok::ai::brain_unit>,boost::_bi::list1<boost::arg<1> > > *this,
        const vostok::ai::brain_unit **a1)
{
  vostok::sound::sound_world *v2; // eax

  v2 = boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)*a1);
  ((void (__thiscall *)(int))LODWORD(this->f_.f_))((int)v2 + HIDWORD(this->f_.f_));
}
