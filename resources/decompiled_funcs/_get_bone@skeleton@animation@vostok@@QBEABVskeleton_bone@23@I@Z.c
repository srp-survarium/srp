const vostok::animation::skeleton_bone *__usercall vostok::animation::skeleton::get_bone@<eax>(
        vostok::animation::skeleton *this@<ecx>,
        unsigned int index@<eax>)
{
  return (const vostok::animation::skeleton_bone *)((char *)&this[1] + 20 * index);
}
