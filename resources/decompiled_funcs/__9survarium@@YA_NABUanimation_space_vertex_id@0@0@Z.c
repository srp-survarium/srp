BOOL __fastcall survarium::operator!=(
        const survarium::animation_space_vertex_id *right,
        const survarium::animation_space_vertex_id *left)
{
  return left->rotation.x != right->rotation.x
      || left->rotation.y != right->rotation.y
      || left->rotation.z != right->rotation.z
      || left->rotation.w != right->rotation.w
      || !vostok::math::float3_pod::is_similar(&left->translation, &right->translation, 0.30000001);
}
