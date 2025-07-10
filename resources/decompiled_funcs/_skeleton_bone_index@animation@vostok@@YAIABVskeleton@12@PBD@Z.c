int __usercall vostok::animation::skeleton_bone_index@<eax>(
        const vostok::animation::skeleton *skeleton@<eax>,
        const char *bone_name@<ecx>)
{
  return ((char *)stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
                    (const vostok::animation::skeleton_bone *)&skeleton[1],
                    (const vostok::animation::skeleton_bone *)&skeleton[1] + skeleton->m_bones_count,
                    (bone_id_predicate)bone_name)
        - (char *)&skeleton[1])
       / 20;
}
