void __userpurge vostok::render::stage_visibility::filter_and_sort(
        vostok::render::stage_visibility *this@<ecx>,
        vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::ambient_light> *a2@<ebx>,
        vostok::render::ambient_light **a3@<edi>,
        vostok::render::environment_probe **probes_generate_pass)
{
  vostok::render::stage_visibility *v4; // ecx
  vostok::render::stage_visibility *v5; // ecx
  vostok::render::stage_visibility *v6; // ecx

  vostok::render::stage_visibility::filter_and_sort_env_probes(this, (int)a3, probes_generate_pass);
  vostok::render::stage_visibility::filter_and_sort_ambient_lights(
    v4,
    (int)a3,
    a2,
    (vostok::render::ambient_light **const)probes_generate_pass);
  vostok::render::stage_visibility::filter_and_sort_particles(
    v5,
    (int)a3,
    (vostok::render::ambient_light **)probes_generate_pass);
  vostok::render::stage_visibility::filter_and_sort_models(
    v6,
    a3,
    (vostok::render::render_surface_instance **)probes_generate_pass);
}
