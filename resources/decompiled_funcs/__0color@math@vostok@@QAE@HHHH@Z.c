void __userpurge vostok::math::color::color(
        vostok::math::color *this@<eax>,
        int a@<ecx>,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  this->m_value = r | ((g | (((a << 8) | b) << 8)) << 8);
}
