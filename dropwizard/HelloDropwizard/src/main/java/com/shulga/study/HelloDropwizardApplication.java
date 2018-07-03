package com.shulga.study;

import io.dropwizard.Application;
import io.dropwizard.setup.Bootstrap;
import io.dropwizard.setup.Environment;

import com.shulga.study.resources.HelloDropwizardResource;
import com.shulga.study.health.TemplateHealthCheck;

public class HelloDropwizardApplication extends Application<HelloDropwizardConfiguration> {

    public static void main(final String[] args) throws Exception {
        new HelloDropwizardApplication().run(args);
    }

    @Override
    public String getName() {
        return "HelloDropwizard";
    }

    @Override
    public void initialize(final Bootstrap<HelloDropwizardConfiguration> bootstrap) {
        // TODO: application initialization
    }

    @Override
    public void run(final HelloDropwizardConfiguration configuration,
                    final Environment environment) {
			final HelloDropwizardResource resource = new HelloDropwizardResource(
        configuration.getTemplate(),
        configuration.getDefaultName()
			);
			final TemplateHealthCheck healthCheck =
        new TemplateHealthCheck(configuration.getTemplate());
			environment.healthChecks().register("template", healthCheck);
			environment.jersey().register(resource);
    }

}
