void __thiscall vostok::sound::sound_scene::insert_environment(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_environment *environment,
        const vostok::math::float4x4 *transform)
{
  this->m_environments_tree->insert(this->m_environments_tree, environment->m_collision, transform);
}
