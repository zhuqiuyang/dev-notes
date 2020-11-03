const fastify = require('fastify')();

function handler(req, reply) {
  reply.send(reply.context.config.output);
}

fastify.get('/en', { config: { output: 'hello world!' } }, handler);
fastify.get('/it', { config: { output: 'ciao mondo!' } }, handler);

fastify.listen(3000);
