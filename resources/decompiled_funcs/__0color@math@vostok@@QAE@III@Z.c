void __userpurge vostok::math::color::color(
        vostok::math::color *this@<eax>,
        unsigned int b@<ecx>,
        unsigned __int8 r,
        unsigned __int8 g)
{
  this->m_value = r | ((g | ((b | 0xFFFFFF00) << 8)) << 8);
}
