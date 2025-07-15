void __userpurge vostok::animation::skeleton_bone::skeleton_bone(
        vostok::animation::skeleton_bone *this@<ecx>,
        vostok::animation::skeleton_bone **a2@<eax>,
        const vostok::animation::skeleton_bone *id,
        const vostok::animation::skeleton_bone *const parent,
        const vostok::animation::skeleton_bone *const children_begin,
        const vostok::animation::skeleton_bone *const children_end,
        const unsigned int mask)
{
  *a2 = this;
  a2[1] = (vostok::animation::skeleton_bone *)id;
  a2[2] = (vostok::animation::skeleton_bone *)parent;
  a2[3] = (vostok::animation::skeleton_bone *)children_begin;
  a2[4] = (vostok::animation::skeleton_bone *)children_end;
}
