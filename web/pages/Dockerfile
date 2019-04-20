FROM php:apache
COPY app/ /var/www/html
RUN rm -rf /var/log/apache2/*
RUN touch /var/log/apache2/access.log
RUN touch /var/log/apache2/error.log
RUN touch /var/log/apache2/other_vhosts_access.log
EXPOSE 80